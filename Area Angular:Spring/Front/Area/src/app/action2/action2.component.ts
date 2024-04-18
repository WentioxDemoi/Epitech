import { BreakpointObserver, Breakpoints } from '@angular/cdk/layout';
import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { map } from 'rxjs';
import { Object } from '../entity/object'
import { ObjectService } from '../service/object.service';

@Component({
selector: 'app-action2',
templateUrl: './action2.component.html',
styleUrls: ['./action2.component.css']
})
export class Action2Component implements OnInit {
    reactionTotal = [];
    actionAvailable = [];

    name: string;

    actionUser: string;

    compareStatus: string;

    result: string;

    latitude: string;

    longitude: string;

    newRepoName: string;

    destroyRepoName: string;

    newBranchName: string;

    destroyBranchName: string;

    compare = [
        "Greater than or equal",
        "less than or equal"
    ]

    allAction = [
        "Nice actual temperature",
        "Nice's actual humidity",
        "Nice's max temperature",
        "Nice's min temperature",
        "Nice's actual pressure",
        "Nice's actual sea level",
        "Nice's actual ground level",
        "Nice's actual feels like temperature"
    ]

    actionDegre = [
        "Nice actual temperature",
        "Nice's max temperature",
        "Nice's min temperature",
        "Nice's actual feels like temperature"
    ]

    actionHpa = [
        "Nice's actual pressure",
        "Nice's actual sea level",
        "Nice's actual ground level"
    ]

    actionPorcent = [
        "Nice's actual humidity"
    ]

  //Reaction1Value recupere les reactions
  reaction1Value: boolean = false;
  reaction2Value: boolean = false;
  reaction3Value: boolean = false;
  reaction4Value: boolean = false;
  reaction5Value: boolean = false;

  buttonDisabled2: boolean;

  service1: boolean = false;
  service2: boolean = false;
  service3: boolean = false;
  service4: boolean = false;
  service5: boolean = false;

  Action = [];

  idClient: any;
  numberAction: number;
  object: Object = { person: 0, action: "", reaction: []};
  constructor(private breakpointObserver: BreakpointObserver, private ObjectService: ObjectService, private router: Router) {}
    cards = this.breakpointObserver.observe(Breakpoints.Handset).pipe(
        map(({ matches }) => {
        return [
            { title: 'Action', cols: 1, rows: 1, image: './assets/img/owm.jpg', name: "owm", type: "Action" },
            { title: 'Reaction', cols: 1, rows: 1, image: './assets/img/github.png', name: "github", type: "Reaction" },
        ];
        })
    );



    ngOnInit() {
        const one = localStorage.getItem('Weather')
        if (one) {
            this.actionAvailable.push(one);
            this.service1 = one.toLowerCase() === 'true';
        }

        const two = localStorage.getItem('Github')
        if (two) {
            this.actionAvailable.push(two);
            this.service2 = two.toLowerCase() === 'true';
        }

        const three = localStorage.getItem('Mail')
        if (three) {
            this.actionAvailable.push(three);
            this.service3 = three.toLowerCase() === 'true';
        }

        const four = localStorage.getItem('Timer')
        if (four) {
            this.actionAvailable.push(four);
            this.service4 = four.toLowerCase() === 'true';
        }
            
        const five = localStorage.getItem('Chuck Norris')
        if (five) {
            this.actionAvailable.push(five);
            this.service5 = five.toLowerCase() === 'true';
        }
        const numberTmp = localStorage.getItem('numberAction')
        if (numberTmp) {
            this.numberAction = Number(numberTmp);
        }
        const tmpId = localStorage.getItem('userId')
        if (tmpId)
            this.idClient = tmpId;
        
        const tmpReaction1 = localStorage.getItem('reaction6')
        if (tmpReaction1)
            this.reaction1Value = JSON.parse(tmpReaction1);
        const tmpReaction2 = localStorage.getItem('reaction7')
        if (tmpReaction2)
            this.reaction2Value = JSON.parse(tmpReaction2);
        const tmpReaction3 = localStorage.getItem('reaction8')
        if (tmpReaction3)
            this.reaction3Value = JSON.parse(tmpReaction3);
        const tmpReaction4 = localStorage.getItem('reaction9')
        if (tmpReaction4)
            this.reaction4Value = JSON.parse(tmpReaction4);
        const tmpReaction5 = localStorage.getItem('reaction10')
        if (tmpReaction5)
            this.reaction5Value = JSON.parse(tmpReaction5);

        const tmpButtonDisabled = localStorage.getItem('buttonDisabled2')
        if (tmpButtonDisabled) {
            this.buttonDisabled2 = JSON.parse(tmpButtonDisabled);
        } else {
            this.buttonDisabled2 = false;
        }
        const tmpAction = localStorage.getItem('actionUser')
        if (tmpAction)
            this.actionUser = tmpAction;
        const tmpCompare = localStorage.getItem('compareStatus')
        if (tmpCompare)
            this.compareStatus = tmpCompare;
        const nameTmp = localStorage.getItem('name')
        if (localStorage)
            this.name = nameTmp;
        
            const newBranchNameTmp = localStorage.getItem('newBranchName')
        if (newBranchNameTmp)
            this.newBranchName = newBranchNameTmp;
        
        const destroyBranchNameTmp = localStorage.getItem('destroyBranchName')
        if (destroyBranchNameTmp)
            this.destroyBranchName = destroyBranchNameTmp;
        
        const newRepoNameTmp = localStorage.getItem('newRepoName')
        if (newRepoNameTmp)
            this.newRepoName = newRepoNameTmp;
        
        const destroyRepoNameTmp = localStorage.getItem('destroyRepoName')
        if (destroyRepoNameTmp)
            this.destroyRepoName = destroyRepoNameTmp;
        
        // GetActionAvailable
        if (this.service1 == true) {
            this.Action.push("Nice actual temperature");
            this.Action.push("Nice's actual humidity");
            this.Action.push("Nice's max temperature");
            this.Action.push("Nice's min temperature");
            this.Action.push("Nice's actual pressure");
            this.Action.push("Nice's actual sea level");
            this.Action.push("Nice's actual ground level");
            this.Action.push("Nice's actual feels like temperature");
        }
        if (this.service2 == true) {
            this.Action.push("A new repo is created");
            this.Action.push("A repo is deleted");
        }
        if (this.service4 == true) {
            this.Action.push("The actual minute is a multiple of five");
        }
    }

  public createPage() {
    this.numberAction += 1;
    localStorage.setItem('numberAction', this.numberAction.toString());
  }

  private getAction(): string {
    let result: string;
    for (let item of this.allAction) {
      if (item == this.actionUser)
        return (result = this.actionUser + " " + this.compareStatus + " " + this.name);
    }
    return this.actionUser;
  }
    
  requete() {
    this.result = this.getAction();
    const reactions = {
    reaction1: this.reaction1Value,
    reaction2: this.reaction2Value,
    reaction3: this.reaction3Value,
    reaction4: this.reaction4Value,
    reaction5: this.reaction5Value,
    };
    if (this.reaction1Value)
        this.reactionTotal.push("Chuck Norris fact");
    if (this.reaction2Value)
        this.reactionTotal.push("Create a repo" + " " + this.newRepoName);
    if (this.reaction3Value)
        this.reactionTotal.push("Create a branch" + " " + this.newBranchName);
    if (this.reaction4Value)
        this.reactionTotal.push("Delete a repo" + " " + this.destroyRepoName);
    if (this.reaction5Value)
        this.reactionTotal.push("Delete a branch" + " " + this.destroyBranchName);
    const payload = {
    reaction: this.reactionTotal
    };
    const json = JSON.stringify(payload);
    this.object.person = this.idClient;
    this.object.action = this.result;
    this.object.reaction = this.reactionTotal;
    this.ObjectService.addObject(this.object).subscribe((response: any) => {
        if (response) {
            localStorage.setItem('reaction6', JSON.stringify(this.reaction1Value));
            localStorage.setItem('reaction7', JSON.stringify(this.reaction2Value));
            localStorage.setItem('reaction8', JSON.stringify(this.reaction3Value));
            localStorage.setItem('reaction9', JSON.stringify(this.reaction4Value));
            localStorage.setItem('reaction10', JSON.stringify(this.reaction4Value));
            localStorage.setItem('actionUser', JSON.stringify(this.actionUser));
            localStorage.setItem('compareStatus', JSON.stringify(this.compareStatus));
            localStorage.setItem('name', JSON.stringify(this.name));
            localStorage.setItem('newBranchName', JSON.stringify(this.newBranchName));
            localStorage.setItem('destroyBranchName', JSON.stringify(this.destroyBranchName));
            localStorage.setItem('newRepoName', JSON.stringify(this.newRepoName));
            localStorage.setItem('destroyRepoName', JSON.stringify(this.destroyRepoName));
            this.buttonDisabled2 = true
            localStorage.setItem('buttonDisabled2', JSON.stringify(this.buttonDisabled2));
        }
    })
    this.reactionTotal = [];
    }
}
