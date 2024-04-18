import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { User } from '../entity/user';

@Injectable({
  providedIn: 'root'
})
export class RegisterService {
  constructor(private http: HttpClient) { }

  registerUser(user: User): Observable<any> {
    const httpOptions = {
      headers: new HttpHeaders({
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      }),
      responseType: 'json' as 'json' // Ajout de l'option responseType
    };
    return this.http.post('http://localhost:8080/registerUser', JSON.stringify(user), httpOptions);
  }
}