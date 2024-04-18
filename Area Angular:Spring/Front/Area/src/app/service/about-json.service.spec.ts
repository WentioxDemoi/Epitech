import { TestBed } from '@angular/core/testing';

import { AboutJsonService } from './about-json.service';

describe('AboutJsonService', () => {
  let service: AboutJsonService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(AboutJsonService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
