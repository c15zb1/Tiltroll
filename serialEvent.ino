String incomingData = "";

void serialEvent(){
  ready = false;
  int inputData = 0; 
  while (Serial.available() > 0) {
    char c = Serial.read();
    incomingData += c; //Serial data read in characters  - add to a string
  }
//  Serial.println(incomingData);
  if(incomingData.length() >19){
    
    AccX = ((incomingData.charAt(0)-'0')*100) + ((incomingData.charAt(1)-'0')*10) + ((incomingData.charAt(2)-'0'));
    AccY = ((incomingData.charAt(4)-'0')*100) + ((incomingData.charAt(5)-'0')*10) + ((incomingData.charAt(6)-'0'));
    incomingData = "";
    
    /*char dataArray[incomingData.length()+1]; 
    incomingData.toCharArray(dataArray, sizeof(dataArray)); 
    for(int ii = 0; ii < incomingData.length()+1; ii++){ //now make data into something useful
      if((dataArray[ii] == '\n') || (dataArray[ii] == ',')){ //time for a new word/coordinate
        inputData ++; 
      } 
      else {
        if(inputData == 0) {
          x += dataArray[ii];
        }
        else if(inputData == 1) {   
          y += dataArray[ii];    
        }
        if(inputData == 2) {
          z += dataArray[ii];
        }
        else if(inputData == 3) {   
          xg += dataArray[ii];    
        }
        else if(inputData == 4) {   
          yg += dataArray[ii];    
        }
      }
    }*/
    ready = true; //coordinates set, time to move on
  }
}

//
//void interpretSerial(){
//  if(ready){
//    char dataArray1[x.length() + 1]; //to turn x, y into coordinates
//    char dataArray2[y.length() + 1]; 
//    char dataArray3[z.length() + 1]; //to turn x, y into coordinates
//    char dataArray4[xg.length() + 1]; 
//    char dataArray5[yg.length() + 1]; 
//    x.toCharArray(dataArray1, sizeof(dataArray1));
//    y.toCharArray(dataArray2, sizeof(dataArray2));
//    z.toCharArray(dataArray3, sizeof(dataArray3));
//    xg.toCharArray(dataArray4, sizeof(dataArray4));
//    yg.toCharArray(dataArray5, sizeof(dataArray5));
//    AccX = atol(dataArray1); //character array to integer - NOT final coordinates
//    AccY = atol(dataArray2);
//    AccZ = atol(dataArray3);
//    GyroX = atol(dataArray4);
//    GyroY = atol(dataArray5);
//    ready = false;
//  }
//}
//
//





