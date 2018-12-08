package got_want

import "testing"

func TestGreeting(t *testing.T) {
	got := Greeting("Yo, Yo, Brother.")
	want := "hello, world, brother."
	if got != want {
		t.Fatalf("expected %q, got %q", want, got)
	}
}
