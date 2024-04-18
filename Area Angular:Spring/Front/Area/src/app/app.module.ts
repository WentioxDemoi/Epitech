import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppComponent } from './app.component';
import { LoginComponent } from './login/login.component';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { AppRoutingModule } from './app-routing.module';

import { FormsModule, ReactiveFormsModule } from '@angular/forms';

import { MatFormFieldModule } from '@angular/material/form-field';
import { MatInputModule } from '@angular/material/input';
import { MatButtonModule } from '@angular/material/button';
import { MatCardModule } from '@angular/material/card';
import { MatToolbarModule } from '@angular/material/toolbar';
import { MatOptionModule } from '@angular/material/core';
import { MatSelectModule } from '@angular/material/select';
import { MatCheckboxModule } from '@angular/material/checkbox';
import { MatSlideToggleModule } from '@angular/material/slide-toggle';
import {MatGridListModule} from '@angular/material/grid-list'

import { DashboardComponent } from './dashboard/dashboard.component';
import { HomeComponent } from './home/home.component';
import { HttpClientModule } from '@angular/common/http';
import { RegisterComponent } from './register/register.component';
import { Action1Component } from './action1/action1.component';
import { Action2Component } from './action2/action2.component';
import { Action3Component } from './action3/action3.component';
import { Action4Component } from './action4/action4.component';
import { RequeteComponent } from './requete/requete.component';
import { ApiServiceComponent } from './api-service/api-service.component';
import { AboutJsonComponent } from './about-json/about-json.component';


@NgModule({
  declarations: [ AppComponent, LoginComponent, DashboardComponent, HomeComponent, RegisterComponent, Action1Component, Action2Component, Action3Component, Action4Component, RequeteComponent, ApiServiceComponent, AboutJsonComponent],
  imports: [
    BrowserModule,
    AppRoutingModule,
    BrowserAnimationsModule,
    MatFormFieldModule,
    MatInputModule,
    MatButtonModule,
    MatCardModule,
    MatToolbarModule,
    FormsModule,
    ReactiveFormsModule,
    HttpClientModule,
    MatOptionModule,
    MatSelectModule,
    MatCheckboxModule,
    MatSlideToggleModule,
    MatGridListModule,
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
