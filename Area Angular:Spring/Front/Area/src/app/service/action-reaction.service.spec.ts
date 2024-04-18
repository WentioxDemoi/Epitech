import { TestBed } from '@angular/core/testing';

import { ActionReactionService } from './action-reaction.service';

describe('ActionReactionService', () => {
  let service: ActionReactionService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(ActionReactionService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
