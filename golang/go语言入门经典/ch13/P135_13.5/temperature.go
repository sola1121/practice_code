package temperature

// 摄氏度转华氏度
func CtoF(c float64) float64 {
	return (c * 9 / 5) + 32
}

// 华氏度转摄氏度
func FtoC(f float64) float64 {
	return (f - 32) * (9 / 5)
}
