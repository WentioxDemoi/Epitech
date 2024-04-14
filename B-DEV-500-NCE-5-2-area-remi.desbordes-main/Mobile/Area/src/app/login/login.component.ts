import { HttpResponse } from '@angular/common/http';
import { Component} from '@angular/core';
import { Router } from '@angular/router';
import { User } from '../entity/user';
import { LoginService } from '../service/login.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})

export class LoginComponent {
  user: User = { email: '', username: '', password: ''};
  username = '';
  password = '';
  email = '';
  loginValid = true
  responseId: any

  constructor(private LoginService: LoginService, private router: Router) {}

  LoginProcess() {
    this.user.username = this.username;
    this.user.password = this.password;
    localStorage.setItem('username', this.username);
    this.LoginService.loginUser(this.user).subscribe((response: any) => {
      if (response) {
        localStorage.setItem('userId', response.userId);
        this.router.navigateByUrl('/dashboard')
      }
    });
  }
}
