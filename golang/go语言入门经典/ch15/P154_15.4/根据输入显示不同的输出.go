package ex

func translateHello(s string) string {
	switch s {
	case "en-US":
		return "hello"
	case "fr-FR":
		return "Bonjour"
	case "it-TT":
		return "Ciao"
	case "zh-CN":
		return "您好"
	default:
		return "hello"
	}
}

func Greeting(name, locale string) string {
	salutation := translateHello(locale)
	return (salutation + string(" ") + name)
}
