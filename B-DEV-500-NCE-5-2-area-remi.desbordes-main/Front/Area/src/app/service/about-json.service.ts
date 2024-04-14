import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class AboutJsonService {

  constructor(private http: HttpClient) { }

  public aboutJson(ipAdress: string) {
    const httpOptions = {
      headers: new HttpHeaders({
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      }),
      responseType: 'text' as 'text'
    };
    return this.http.get(`http://localhost:8080/about.json?ipAdress=${ipAdress}`, httpOptions);
  }
}
