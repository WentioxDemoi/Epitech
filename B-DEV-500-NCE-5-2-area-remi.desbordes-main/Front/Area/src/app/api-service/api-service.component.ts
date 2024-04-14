import { Component, OnInit } from '@angular/core';
import { Breakpoints, BreakpointObserver } from '@angular/cdk/layout';
import { map } from 'rxjs';

@Component({
    selector: 'app-api-service',
    templateUrl: './api-service.component.html',
    styleUrls: ['./api-service.component.css']
})
export class ApiServiceComponent implements OnInit{

    service1: boolean = false;
    service2: boolean = false;
    service3: boolean = false;
    service4: boolean = false;
    service5: boolean = false;

    numberAction: number;

    ngOnInit(): void {
        const numberTmp = localStorage.getItem('numberAction')
        if (numberTmp) {
            this.numberAction = Number(numberTmp);
        } else {
            this.numberAction = 0;
        }
        const one = localStorage.getItem('Weather')
        if (one)
            this.service1 = one.toLowerCase() === 'true';
        
        const two = localStorage.getItem('Github')
        if (two)
            this.service2 = two.toLowerCase() === 'true';
        const three = localStorage.getItem('Mail')
        if (three)
            this.service3 = three.toLowerCase() === 'true';
        const four = localStorage.getItem('Timer')
        if (four)
            this.service4 = four.toLowerCase() === 'true';
        const five = localStorage.getItem('Chuck Norris')
        if (five)
            this.service5 = five.toLowerCase() === 'true';
    }

    public createPage() {
        this.numberAction += 1;
        localStorage.setItem('numberAction', this.numberAction.toString());
    }

    constructor(private breakpointObserver: BreakpointObserver) {}

    cards = this.breakpointObserver.observe(Breakpoints.Handset).pipe(
        map(({ matches }) => {
        return [
            { title: 'Open Weather Map', cols: 1, rows: 1, image: './assets/img/owm.jpg', name: "owm", status: this.service1 },
            { title: 'Github', cols: 1, rows: 1, image: './assets/img/github.png', name: "github", status: this.service2 },
            { title: 'Spring Boot Mail', cols: 1, rows: 1, image: './assets/img/mail.jpeg', name: "sbm", status: this.service3 },
            { title: 'Timer', cols: 1, rows: 1, image: './assets/img/timer.png', name: "timer", status: this.service4 },
            { title: 'Chuck Norris', cols: 1, rows: 1, image: './assets/img/chuck-norris.png', name: "ymr", status: this.service5 },
        ];
        })
    );
    updateService(name: string, service: boolean) {
        if (name == 'Open Weather Map') {
            this.service1 = service;
            localStorage.setItem('Weather', this.service1.toString())
        }
        if (name == 'Github') {
            this.service2 = service;
            localStorage.setItem('Github', this.service2.toString())
        }
        if (name == 'Spring Boot Mail') {
            this.service3 = service;
            localStorage.setItem('Mail', this.service3.toString())
        }
        if (name == 'Timer') {
            this.service4 = service;
            localStorage.setItem('Timer', this.service4.toString())
        }
        if (name == 'Chuck Norris') {
            this.service5 = service;
            console.log(this.service5)
            localStorage.setItem('Chuck Norris', this.service5.toString())
        }
    }
}