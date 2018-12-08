package ex

import "testing"

type GreetingTest struct {
	name  string
	local string
	want  string
}

var greetingTests = []GreetingTest{
	{"Tom", "en-US", "hello Tom"},
	{"Ben", "fr-FR", "Bonjour Ben"},
	{"王", "zh-CN", "您好 王"},
}

func TestGreetingHello(t *testing.T) {
	for _, test := range greetingTests {
		got := Greeting(test.name, test.local)
		want := test.want
		if got != want {
			t.Fatalf("GreetingHello(%s, %s) = %v; want: %v", test.name, test.local, got, test.want)
		}
	}
}
