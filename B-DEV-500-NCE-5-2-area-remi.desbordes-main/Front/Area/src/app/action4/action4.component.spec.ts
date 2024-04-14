import { ComponentFixture, TestBed } from '@angular/core/testing';

import { Action4Component } from './action4.component';

describe('Action4Component', () => {
  let component: Action4Component;
  let fixture: ComponentFixture<Action4Component>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ Action4Component ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(Action4Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
