import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class HeatingCostService {
  
  calculateCost(data: any): number {
    let costPerUnit;
    let insulationFactor;
    let surface = data.surface;
    let priceOfFuel;
    let amountOfResidents = data.amountOfResidents;
    

    switch (data.heatingSource) {
      case 'electricity':
        costPerUnit = 1;
        break;
      case 'gas':
        costPerUnit = 5;
        break;
      case 'wood':
        costPerUnit = 10;
        break;

      default:
        costPerUnit = 1;
    }

    if(data.insulation === 'high') {
      insulationFactor = 10;
    }
    else if(data.insulation === 'medium') {
      insulationFactor = 20;
    }
    else{
      insulationFactor = 30;
    }

    switch (data.priceOfFuel) {
      case 'electricity':
        priceOfFuel = 1;
        break;
      case 'wood':
        priceOfFuel = 0.1;
        break;
      case 'gas':
        priceOfFuel = 0.01;
        break;

      default:
        priceOfFuel = 1;
    }
    return (surface * costPerUnit * insulationFactor * priceOfFuel) / amountOfResidents;
  }
}