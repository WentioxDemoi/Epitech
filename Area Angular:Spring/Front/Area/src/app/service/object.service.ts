import { HttpClient, HttpHeaders, HttpResponse } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class ObjectService {

  constructor(private http: HttpClient) { }
  
  addObject(object: Object): Observable<any> {
    console.log(object)
    console.log(JSON.stringify(object))
    const httpOptions = {
      headers: new HttpHeaders({
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      }),
      responseType: 'json' as 'json'
    };
    return this.http.post('http://localhost:8080/addObject', JSON.stringify(object), httpOptions)
  }
}