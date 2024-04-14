import { NgModule } from "@angular/core";
import { Routes, RouterModule } from "@angular/router";
import { LoginComponent } from "./login/login.component";
import { HomeComponent } from "./home/home.component";
import { RegisterComponent } from "./register/register.component";
import { DashboardComponent } from "./dashboard/dashboard.component";
import { Action1Component } from "./action1/action1.component";
import { Action2Component } from "./action2/action2.component";
import { Action3Component } from "./action3/action3.component";
import { Action4Component } from "./action4/action4.component";
import { RequeteComponent } from "./requete/requete.component";
import { ApiServiceComponent } from "./api-service/api-service.component";
import { AboutJsonComponent } from "./about-json/about-json.component";

const routes: Routes = [
    {
      path: 'dashboard',
      component: DashboardComponent
    },
    {
      path: 'register',
      component: RegisterComponent
    },
    {
      path: 'login',
      component: LoginComponent
    },
     {
       path: 'action1',
       component: Action1Component
     },
    {
      path: 'action2',
      component: Action2Component
    },
    {
      path: 'action3',
      component: Action3Component
    },
    {
      path: 'action4',
      component: Action4Component
    },
    {
      path: 'requete',
      component: RequeteComponent
    },
    {
      path: '',
      component: HomeComponent
    },
    {
      path: 'service',
      component: ApiServiceComponent
    },
    {
      path: 'about.json',
      component: AboutJsonComponent
    }
  ];

@NgModule({
    imports: [RouterModule.forRoot(routes)],
    exports: [RouterModule]
})

export class AppRoutingModule { }