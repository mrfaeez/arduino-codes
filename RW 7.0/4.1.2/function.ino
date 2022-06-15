void forward(int pwmLeft, int pwmRight)
{
  //analogWrite (EN_A_LEFT, pwmLeft);
  analogWrite (IN_1_LEFT, pwmLeft);
  analogWrite (IN_2_LEFT, 0);
  //analogWrite (EN_A_LEFT, pwmLeft);
  analogWrite (IN_3_RIGHT, pwmRight);
  analogWrite (IN_4_RIGHT, 0);
  //analogWrite (EN_B_RIGHT, pwmRight);
}
