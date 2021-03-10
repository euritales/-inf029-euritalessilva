
float promocao_gasolina(float litro)
{
	float valor;
	
	if(litro > 25){
		valor = (litro * 5.415);
	}else{
		valor = (litro * 5.7);
	}
		
	return (valor);
	
  }

float promocao_alcool(float litro)
{
	float valor;
	
	if(litro > 25){
		valor = (litro * 3.744);
	}else{
		valor = (litro * 3.9);
	}
		
	return (valor);
	
  }