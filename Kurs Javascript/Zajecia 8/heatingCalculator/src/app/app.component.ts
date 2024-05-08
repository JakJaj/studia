// Step 2: Create a form in the main component (app.component.ts)

import { Component } from '@angular/core';
import { FormBuilder, FormGroup } from '@angular/forms';
import { HeatingCostService } from './heating-cost.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css'],
})
export class AppComponent {
  title = 'heatingCostSimulator';
  heatingForm: FormGroup;
  cost: number = 0;

  constructor(private formBuilder: FormBuilder, private heatingCostService: HeatingCostService) {
    this.heatingForm = this.formBuilder.group({
      surface: '80',
      heatingSource: ['electricity'],
      insulation: ['high'],
      amountOfResidents: '1',
      priceOfFuel: '1'
    });
  }

  onSubmit(): void {
    this.cost = this.heatingCostService.calculateCost(this.heatingForm.value);
    
  }
}