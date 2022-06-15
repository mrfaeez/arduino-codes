void forwardleft()
{
  //analogWrite (EN_A_LEFT, pwmLeft);
  analogWrite (IN_1_LEFT, 200);
  analogWrite (IN_2_LEFT, 0);
  
}

void forwardright()
{
  analogWrite (IN_3_RIGHT, 200);
  analogWrite (IN_4_RIGHT, 0);
  //analogWrite (EN_B_RIGHT, pwmRight);
}
