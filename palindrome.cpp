#include <iostream>

// Define is_palindrome() here:
bool is_palindrome(std::string text){
  std::string rev_text;
  for (int i = text.size() - 1; i >= 0; i--){
    rev_text.push_back(text[i]);
  } 
  //std::cout << rev_text << "\n";
  return !rev_text.compare(text);
}

int main() {
  
  std::cout << is_palindrome("madam") << "\n";
  std::cout << is_palindrome("ada") << "\n";
  std::cout << is_palindrome("lovelace") << "\n";
  
}
