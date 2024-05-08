import { ReactiveFormsModule } from '@angular/forms';
import { Component } from '@angular/core';
import { TemperatureConverterComponent } from './temperature-converter/temperature-converter.component';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [TemperatureConverterComponent, ReactiveFormsModule],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'temperatureConverter';
}
