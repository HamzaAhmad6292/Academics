object PalindromeChecker {
  def isPalindrome(str: String): Boolean = {
    val cleanStr = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase 
    cleanStr == cleanStr.reverse 
  }

  @main def run(): Unit = {
    val testStrings = List("racecar","elo")

    for (str <- testStrings) {
      if (isPalindrome(str)) {
        println(s"'$str' is a palindrome.")
      } else {
        println(s"'$str' is not a palindrome.")
      }
    }
  }
}
