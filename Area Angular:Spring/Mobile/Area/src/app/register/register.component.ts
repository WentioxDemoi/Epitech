import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { RegisterService } from '../service/register-service';
import { User } from '../entity/user';
import { HttpResponse } from '@angular/common/http';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent {
  user: User = { email: '', username: '', password: ''};
  email = '';
  username = '';
  password = '';
  loginValid = true

  constructor(private ResgisterService: RegisterService, private router: Router) {
  }

  registerProcess() {
    this.user.email = this.email;
    this.user.username = this.username;
    this.user.password = this.password;
    localStorage.setItem('username', this.username);
    this.ResgisterService.registerUser(this.user).subscribe((response: any) => {
      if (response) {
        localStorage.setItem('userId', response.userId);
        this.router.navigateByUrl('/dashboard')
        console.log(response)
      }
    });
  }
}