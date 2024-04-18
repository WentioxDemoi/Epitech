import { Component, OnInit } from '@angular/core';
import { HttpResponse } from '@angular/common/http';
import { Router } from '@angular/router';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.css']
})

export class DashboardComponent implements OnInit {

  numberAction: number = 0;
  username: string;

  ngOnInit() {
    const tmp = localStorage.getItem('numberAction');
    if (!isNaN(Number(tmp))) {
      console.log(tmp)
      this.numberAction = Number(tmp);
      console.log(this.numberAction)
    }
    this.username = localStorage.getItem('username') || 'KDC777';
  }

  constructor(private router: Router) {}

  public createPage() {
    this.numberAction += 1;
    console.log(this.numberAction)
    localStorage.setItem('numberAction', this.numberAction.toString())
  }

}
