import { ComponentFixture, TestBed } from '@angular/core/testing';

import { Action3Component } from './action3.component';

describe('Action3Component', () => {
  let component: Action3Component;
  let fixture: ComponentFixture<Action3Component>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ Action3Component ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(Action3Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
