import { TestBed } from '@angular/core/testing';

import { HeatingCostService } from './heating-cost.service';

describe('HeatingCostService', () => {
  let service: HeatingCostService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(HeatingCostService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
