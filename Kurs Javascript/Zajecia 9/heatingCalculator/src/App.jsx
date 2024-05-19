import React, {useState} from 'react';

export default function App() {

  const [selectedSource, setSelectedSource] = useState([true, false, false]);
  const [selectedOption, setSelectedOption] = useState(25);
  const options = [
    { value: '5', label: 'Bardzo dobra' },
    { value: '10', label: 'Dobra' },
    { value: '15', label: 'Średnia' },
    { value: '20', label: 'Słaba' },
    { value: '25', label: 'Bardzo słaba' },
  ];

  const [surface, setSurface] = useState("");
  const [residents, setResidents] = useState("");
  const [fuelPrice, setFuelPrice] = useState("");

  return (
    <>
      <div className="heading">
        <h1>Kalkulator ogrzewania</h1>
      </div>

      <div className="centrum">
        <div className="centrum-child">
          <h3>Dane domu</h3>
          <SelectingSource />

          <p>Powierzchnia</p>
          <div className='postfix'>
            <input 
              type="number" 
              placeholder="Wpisz powierzchnie" 
              value={surface}
              onChange={(event) => setSurface(event.target.value)}
            />
            <p>m²</p>
          </div> 

          <SelectField label="Stopień izolacji budynku" options={options} />

          <p>Liczba mieszkańców</p>
          <div className='postfix'>
            <input 
              type="number" 
              placeholder="Wpisz powierzchnie" 
              value={residents}
              onChange={(event) => setResidents(event.target.value)}
            />
            <p>m²</p>
          </div> 

          <FuelPrice />
        </div>
        
        <div className="result">
          <h3>Szacowana cena ogrzewania</h3>
          <Result />
        </div>
        

      </div> 
      
    </>
  );

function InputField({ label, placeholder, postfix, value, setter}) {
  
  function handleChange(event){
  setter(event.target.value);
  }

  return (
  <>
    <p>{label}</p>
    <div className='postfix'>
    <input 
      type="number" 
      placeholder={placeholder} 
      value={value}
      onChange={handleChange}
    />
    <p>{postfix}</p>
    </div>
  </>
  );
}

function SelectField({ label, options }) {

  const handleChange = (event) => {
    setSelectedOption(event.target.value);
  }

  return (
    <>
      <p>{label}</p>
      <select value={selectedOption} onChange={handleChange}>
        {options.map((option, index) => <option key={index} value={option.value}>{option.label}</option>)}
      </select>
    </>
  );
}

function SourceButton({ label, index}) {
  
  if (selectedSource[index] === true){
  return (
    <button className="sourceButton, selected">{label}</button>
  );
}
  return (
    <button onClick={() => setSelectedSource(selectedSource.map((value, i) => i === index ? true : false),)}
    className="sourceButton">{label}</button>
  );
}

function SelectingSource(){
  return (
    <>
      <p>Sposób ogrzewania</p>
      <div>
        <SourceButton label="Gaz" index={0}/>
        <SourceButton label="Prąd" index={1}/>
        <SourceButton label="Węgiel" index={2} />
      </div>
    </>
  );
}

function FuelPrice(){
  if(selectedSource[0] === true){
    return (
    <>
    <p>Wpisz cene gazu</p>
          <div className='postfix'>
            <input 
              type="number" 
              placeholder="Wpisz cene gazu" 
              value={fuelPrice}
              onChange={(event) => setFuelPrice(event.target.value)}
            />
            <p> zł/m³</p>
          </div> 
    </>
    );
  }
  if (selectedSource[1] === true){
    return (
      <>
      <p>Wpisz cene prądu</p>
            <div className='postfix'>
              <input 
                type="number" 
                placeholder="Wpisz cene prądu" 
                value={fuelPrice}
                onChange={(event) => setFuelPrice(event.target.value)}
              />
              <p> zł/kWh</p>
            </div> 
      </>
      );
  }
  if (selectedSource[2] === true){
    return (
      <>
      <p>Wpisz cene węgla</p>
            <div className='postfix'>
              <input 
                type="number" 
                placeholder="Wpisz cene węgla" 
                value={fuelPrice}
                onChange={(event) => setFuelPrice(event.target.value)}
              />
              <p> zł/t</p>
            </div> 
      </>
      );
  }
}

function Result(){

  let price = (surface * fuelPrice * selectedOption) / residents;

  if( !isNaN(price) || isFinite(price)){
  return (
    <>
    <p className='result-text'>{price}</p>
    </>
  );}
  
    return (
      <>
      <p className='result-text'>Wpisz dane</p>
      </>
    );
  
}
}