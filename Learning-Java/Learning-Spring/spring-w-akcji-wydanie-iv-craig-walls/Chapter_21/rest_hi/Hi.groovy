@RestController
class Hi {
	@RequestMapping("/")
	String hi() {
		"Cześć!"
	}
}