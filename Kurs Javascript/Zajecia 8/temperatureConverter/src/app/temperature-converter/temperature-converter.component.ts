import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup} from '@angular/forms';

@Component({
  selector: 'app-temperature-converter',
  standalone: true,
  imports: [],
  templateUrl: './temperature-converter.component.html',
  styleUrl: './temperature-converter.component.css'
})
export class TemperatureConverterComponent implements OnInit {
  form: FormGroup;
  calculationResult: number = 0;

  constructor(private fb: FormBuilder) {
    this.form = this.fb.group({
      surface: [''],
      heatingMethod: [''],
      currentBill: ['']
    });
  }

  ngOnInit() {
    this.form.valueChanges.subscribe(values => {
      this.calculate(values);
    });
  }

  calculate(values: any) {
    console.log(values);
    // Perform calculation based on form values
    this.calculationResult = values
  }
}
