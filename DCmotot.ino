int a = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  for(int i = 9 ;i>=6; i--){
  	pinMode(i,OUTPUT);
  }
  
}

void loop()
{
  if(Serial.available()>0){
   a = Serial.parseInt();
    if(a==1){
    	//forward - clockwise --> T1-L and T2-H
  		digitalWrite(13,HIGH);
  		digitalWrite(12,LOW);
  		digitalWrite(11,HIGH);
  		digitalWrite(10,LOW);
      	digitalWrite(9,HIGH);
        for(int i = 8 ;i>=6; i--){
  			digitalWrite(i,LOW);
 		 }
  
  		
    }
    else if(a==2){
     //backward - AC --> T1-H and T2-LOW
  	digitalWrite(13,LOW);
  	digitalWrite(12,HIGH);
  	digitalWrite(11,LOW);
  	digitalWrite(10,HIGH);
    digitalWrite(8,HIGH);
      for(int i = 9 ;i>=6; i--){
        if(i!=8){
  			digitalWrite(i,LOW);
        }
 	  }
    }
    
    else if(a==3){
      //right - DC1 - CL and DC2 - stop
  		digitalWrite(13,LOW);
  		digitalWrite(12,HIGH);
  		digitalWrite(11,LOW);
  		digitalWrite(10,LOW);
      	digitalWrite(7,HIGH);
      for(int i = 9 ;i>=6; i--){
        if(i!=7){
  			digitalWrite(i,LOW);
        }
 	  }
    }
    
    else if(a==4){
    	//left - DC1 - stop and DC2 - Clockwise
  		digitalWrite(13,LOW);
  		digitalWrite(12,LOW);
  		digitalWrite(11,LOW);
  		digitalWrite(10,HIGH);
        digitalWrite(6,HIGH);
      for(int i = 9 ;i>=6; i--){
        if(i!=6){
  			digitalWrite(i,LOW);
        }
 	  }
    }
    
    else{
    	//stop - DC1 - stop and DC2 - stop
  		digitalWrite(13,LOW);
  		digitalWrite(12,LOW);
  		digitalWrite(11,LOW);
  		digitalWrite(10,LOW);
      for(int i = 9 ;i>=6; i--){
  			digitalWrite(i,LOW);
 		 }
    }
      
  
  }
}
