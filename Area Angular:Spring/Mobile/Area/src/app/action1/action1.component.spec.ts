import { ComponentFixture, TestBed } from '@angular/core/testing';

import { Action1Component } from './action1.component';

describe('Action1Component', () => {
  let component: Action1Component;
  let fixture: ComponentFixture<Action1Component>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ Action1Component ]
    })
    .compileComponents();

    fixture = TestBed.createComponent(Action1Component);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
