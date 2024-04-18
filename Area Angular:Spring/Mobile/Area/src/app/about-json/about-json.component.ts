import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { AboutJsonService } from '../service/about-json.service';
import { IpServiceService } from '../service/ip-service.service';

@Component({
  selector: 'app-about-json',
  templateUrl: './about-json.component.html',
  styleUrls: ['./about-json.component.css']
})
export class AboutJsonComponent implements OnInit {
  numberAction: number = 0;
  json: string;
  ipAddress: string;

  constructor(private about: AboutJsonService, private ip: IpServiceService) { }

  ngOnInit() {
    const tmp = localStorage.getItem('numberAction');
    if (!isNaN(Number(tmp))) {
      console.log(tmp)
      this.numberAction = Number(tmp);
      console.log(this.numberAction)
    }
    this.ip.getIpAddress().subscribe((data: any) => {
      this.ipAddress = data.ip;
      this.about.aboutJson(this.ipAddress).subscribe((data: any) => {
        this.json = data;
      });
    });
  }

  public createPage() {
    this.numberAction += 1;
    console.log(this.numberAction)
    localStorage.setItem('numberAction', this.numberAction.toString())
  }
}
