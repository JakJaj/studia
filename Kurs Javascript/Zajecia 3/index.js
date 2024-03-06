$(document).ready(function() {

    var selectedConversion = "Masa";
    var firstUnit = null;
    var secondUnit = null;
    var input = NaN;
    changeDropdownList(selectedConversion);


    //Sprawdzenie czy wybrano jednostki i konwersja
    $("#convertButton").click(function(){
        input = parseFloat($("#firstInput").val());
        if(checkForEmptyFields(firstUnit, secondUnit, input)){
        
            switch(selectedConversion){
                case "Masa":
                    massConversion(firstUnit, secondUnit);
                    console.log("Masa");        
                    break;
                case "Dlugosc":
                    lengthConversion(firstUnit,secondUnit);
                    console.log("Dlugosc");
                    break;
                case "Temperatura":
                    temperatureConversion(firstUnit, secondUnit);
                    console.log("Temperatura");
                    break;
                default:
                    console.log("Nie wybrano konwersji");
            }
        }
    })
    $(".nav-item > a").click(function() {
        $(".nav-item > a").removeClass("active");
        $(this).addClass("active");
        selectedConversion = $(this).text();
        console.log(selectedConversion);
        $("#title-text").text(selectedConversion);
        changeDropdownList(selectedConversion);
    });

    $(document).on('click', '.dropdown-item', function() {
        var dropdownButton = $(this).closest('.dropdown').find('.dropdown-toggle');
        dropdownButton.text($(this).text());

        if(dropdownButton.attr("id") == "firstUnit"){
            firstUnit = dropdownButton.text();
            console.log("First Unit: " + firstUnit);
        }
        else if (dropdownButton.attr("id") == "secondUnit"){
            secondUnit = dropdownButton.text();
            console.log("Second Unit: " + secondUnit);
        }
        
    });
});

function changeDropdownList(selectedConversion){
    var firstUnitList = $("#firstUnitList");
    var secondUnitList = $("#secondUnitList");

    switch(selectedConversion){
        case "Masa":
            firstUnitList.empty();
            secondUnitList.empty();
            firstUnitList.append('<a class="dropdown-item" href="#">Kilogram</a>');
            firstUnitList.append('<a class="dropdown-item" href="#">Funt</a>');
            firstUnitList.append('<a class="dropdown-item" href="#">Uncja</a>');
            firstUnitList.append('<a class="dropdown-item" href="#">Karat</a>');

            secondUnitList.append('<a class="dropdown-item" href="#">Kilogram</a>');
            secondUnitList.append('<a class="dropdown-item" href="#">Funt</a>');
            secondUnitList.append('<a class="dropdown-item" href="#">Uncja</a>');
            secondUnitList.append('<a class="dropdown-item" href="#">Karat</a>');
            break;
        case "Dlugosc":
            firstUnitList.empty();
            secondUnitList.empty();

            firstUnitList.append('<a class="dropdown-item" href="#">Metr</a>');
            firstUnitList.append('<a class="dropdown-item" href="#">Cale</a>');
            firstUnitList.append('<a class="dropdown-item" href="#">Jard</a>');
            firstUnitList.append('<a class="dropdown-item" href="#">Mila</a>');

            secondUnitList.append('<a class="dropdown-item" href="#">Metr</a>');
            secondUnitList.append('<a class="dropdown-item" href="#">Cale</a>');
            secondUnitList.append('<a class="dropdown-item" href="#">Jard</a>');
            secondUnitList.append('<a class="dropdown-item" href="#">Mila</a>');
            break;
        case "Temperatura":
            firstUnitList.empty();
            secondUnitList.empty();
            firstUnitList.append('<a class="dropdown-item" href="#">Celsjusz</a>');
            firstUnitList.append('<a class="dropdown-item" href="#">Fahrenheit</a>');
            firstUnitList.append('<a class="dropdown-item" href="#">Kelvin</a>');

            secondUnitList.append('<a class="dropdown-item" href="#">Celsjusz</a>');
            secondUnitList.append('<a class="dropdown-item" href="#">Fahrenheit</a>');
            secondUnitList.append('<a class="dropdown-item" href="#">Kelvin</a>');
            break;
        default:
            console.log("Nie wybrano konwersji");
    }
}

function massConversion(firstUnit, secondUnit){
        var firstValue = parseFloat($("#firstInput").val());
        var result = 0;

        if(firstUnit === "Kilogram"){
            if(secondUnit === "Kilogram"){
                result = firstValue;
            } else if(secondUnit === "Funt"){
                result = firstValue * 2.20462;
            } else if(secondUnit === "Uncja"){
                result = firstValue * 35.274;
            } else if(secondUnit === "Karat"){
                result = firstValue * 5000;
            }
        } else if(firstUnit === "Funt"){
            if(secondUnit === "Kilogram"){
                result = firstValue * 0.453592;
            } else if(secondUnit === "Funt"){
                result = firstValue;
            } else if(secondUnit === "Uncja"){
                result = firstValue * 16;
            } else if(secondUnit === "Karat"){
                result = firstValue * 2267.96;
            }
        } else if(firstUnit === "Uncja"){
            if(secondUnit === "Kilogram"){
                result = firstValue * 0.0283495;
            } else if(secondUnit === "Funt"){
                result = firstValue * 0.0625;
            } else if(secondUnit === "Uncja"){
                result = firstValue;
            } else if(secondUnit === "Karat"){
                result = firstValue * 141.748;
            }
        } else if(firstUnit === "Karat"){
            if(secondUnit === "Kilogram"){
                result = firstValue * 0.0002;
            } else if(secondUnit === "Funt"){
                result = firstValue * 0.000440925;
            } else if(secondUnit === "Uncja"){
                result = firstValue * 0.00705479;
            } else if(secondUnit === "Karat"){
                result = firstValue;
            }
        }

        $("#result").text(firstValue + " " + firstUnit + " to: " + result.toFixed(5) + ": " + secondUnit);
    
}

function lengthConversion(firstUnit, secondUnit) {
    var firstValue = parseFloat($("#firstInput").val());
    var result = 0;
    if (firstUnit === "Metr") {
        if (secondUnit === "Metr") {
            result = firstValue;
        } else if (secondUnit === "Cale") {
            result = firstValue * 39.3701;
        } else if (secondUnit === "Jard") {
            result = firstValue * 1.09361;
        } else if (secondUnit === "Mila") {
            result = firstValue * 0.000621371;
        }
    } else if (firstUnit === "Cale") {
        if (secondUnit === "Metr") {
            result = firstValue * 0.0254;
        } else if (secondUnit === "Cale") {
            result = firstValue;
        } else if (secondUnit === "Jard") {
            result = firstValue * 0.0277778;
        } else if (secondUnit === "Mila") {
            result = firstValue * 0.000015783;
        }
    } else if (firstUnit === "Jard") {
        if (secondUnit === "Metr") {
            result = firstValue * 0.9144;
        } else if (secondUnit === "Cale") {
            result = firstValue * 36;
        } else if (secondUnit === "Jard") {
            result = firstValue;
        } else if (secondUnit === "Mila") {
            result = firstValue * 0.000568182;
        }
    } else if (firstUnit === "Mila") {
        if (secondUnit === "Metr") {
            result = firstValue * 1609.34;
        } else if (secondUnit === "Cale") {
            result = firstValue * 63360;
        } else if (secondUnit === "Jard") {
            result = firstValue * 1760;
        } else if (secondUnit === "Mila") {
            result = firstValue;
        }
    }
    $("#result").text(firstValue + " " + firstUnit + " to: " + result.toFixed(5) + ": " + secondUnit);
}

function temperatureConversion(firstUnit, secondUnit) {
    var firstValue = parseFloat($("#firstInput").val());
    var result = 0;
    if (firstUnit === "Celsjusz") {
        if (secondUnit === "Celsjusz") {
            result = firstValue;
        } else if (secondUnit === "Fahrenheit") {
            result = (firstValue * 9/5) + 32;
        } else if (secondUnit === "Kelvin") {
            result = firstValue + 273.15;
        }
    } else if (firstUnit === "Fahrenheit") {
        if (secondUnit === "Celsjusz") {
            result = (firstValue - 32) * 5/9;
        } else if (secondUnit === "Fahrenheit") {
            result = firstValue;
        } else if (secondUnit === "Kelvin") {
            result = (firstValue + 459.67) * 5/9;
        }
    } else if (firstUnit === "Kelvin") {
        if (secondUnit === "Celsjusz") {
            result = firstValue - 273.15;
        } else if (secondUnit === "Fahrenheit") {
            result = (firstValue * 9/5) - 459.67;
        } else if (secondUnit === "Kelvin") {
            result = firstValue;
        }
    }
    $("#result").text(firstValue + " " + firstUnit + " to: " + result.toFixed(5) + ": " + secondUnit);
}

function checkForEmptyFields(firstUnit, secondUnit, input){
    if(firstUnit == null){
        $("#firstUnitError").text("Nie wybrano jednostki")
        .addClass("bg-danger-subtle")
        .addClass("mt-2")
        .addClass("border")
        .addClass("border-danger-subtle");
        return false;
    } else if(firstUnit != null){
        $("#firstUnitError").text("")
        .removeClass("bg-danger-subtle")
        .removeClass("mt-2")
        .removeClass("border")
        .removeClass("border-danger-subtle");
    }
    
    if(secondUnit == null){
        $("#secondUnitError").text("Nie wybrano jednostki")
        .addClass("bg-danger-subtle")
        .addClass("mt-2")
        .addClass("border")
        .addClass("border-danger-subtle");
        return false;
    }else if(firstUnit != null){
        $("#secondUnitError").text("")
        .removeClass("bg-danger-subtle")
        .removeClass("mt-2")
        .removeClass("border")
        .removeClass("border-danger-subtle");
    }

    if(isNaN(input)){
        $("#inputError").text("Nie podano wartości")
        .addClass("bg-danger-subtle")
        .addClass("mt-2")
        .addClass("border")
        .addClass("border-danger-subtle");
        return false;
    }
    else if(!isNaN(input)){
        $("#inputError").text("")
        .removeClass("bg-danger-subtle")
        .removeClass("mt-2")
        .removeClass("border")
        .removeClass("border-danger-subtle");
    }
    console.log(firstUnit + " " + secondUnit + " "  + input);
    return true;
}