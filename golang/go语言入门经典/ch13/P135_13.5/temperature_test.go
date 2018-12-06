package temperature

import (
	"testing"
)

type temperatureTest struct {
	i        float64
	expected float64
}

var CtoFTest = []temperatureTest{
	{4.1, 39.38},
	{10, 50},
	{-10, 14},
}

var FtoCTest = []temperatureTest{
	{32, 0},
	{50, 10},
	{5, -15},
}

func TestCtoF(t *testing.T) {
	for _, tt := range CtoFTest {
		actual := CtoF(tt.i)
		if actual != tt.expected {
			t.Errorf("expected %v, actual %v", tt.expected, actual)
		}
	}
}

func TestFtoC(t *testing.T) {
	for _, tt := range FtoCTest {
		actual := FtoC(tt.i)
		if actual != tt.expected {
			t.Errorf("expected %v, actual %v", tt.expected, actual)
		}
	}
}

// func TestXxx(*testing.T)
