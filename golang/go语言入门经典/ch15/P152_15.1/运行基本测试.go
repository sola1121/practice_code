package example

import "testing"

func TestTruth(t *testing.T) {
	if 1 != 1 {
		t.Fatal("Oh my god, the one is not equal to one.")
	}
}
