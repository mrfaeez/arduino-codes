void callib() {

  
    ldrVal1 = analogRead (LDR_PIN1);
    if (ldrVal1 <= minVal1)
      minVal1 = ldrVal1;
    if (ldrVal1 >= maxVal1)
      maxVal1 = ldrVal1;
    ldr1 = (maxVal1 + minVal1) / 2;

    ldrVal2 = analogRead (LDR_PIN2);
    if (ldrVal2 <= minVal2)
      minVal2 = ldrVal2;
    if (ldrVal2 >= maxVal2)
      maxVal2 = ldrVal2;
    ldr2 = (maxVal2 + minVal2) / 2;

    ldrVal3 = analogRead (LDR_PIN3);
    if (ldrVal3 <= minVal3)
      minVal3 = ldrVal3;
    if (ldrVal3 >= maxVal3)
      maxVal3 = ldrVal3;
    ldr3 = (maxVal3 + minVal3) / 2;
  
}
