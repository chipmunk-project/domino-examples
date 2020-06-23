#include <iostream>

#define THRESH 1000
#define ARRAY_SIZE 1000000

// Policy 6 from SNAP paper
void spam_detection(int &smtp_mta, int &mail_counter, int &mta_dir) {
  // TODO: Compiler bug
  smtp_mta = smtp_mta;

  // Check unknown (1)
  if (mta_dir == 1) {
    // Set tracked (2)
    mta_dir = 2;
    mail_counter = 0;
  }

  // Check tracked (2)
  if (mta_dir == 2) {
    mail_counter = mail_counter + 1;
    if (mail_counter == THRESH) {
      // Set spammer (3)
      // TODO: The SNAP paper says mta_directory here. I think that's a typo.
      mta_dir = 3;
    } 
  }
}

int main(int argc, char **argv) {
  int smtp_mta, mail_counter, mta_dir;
  std::cout << "input the initial value of p.smtp_mta: " << std::endl;
  std::cin >> smtp_mta;
  std::cout << "input the initial value of mail_counter: " << std::endl;
  std::cin >> mail_counter;
  std::cout << "input the initial value of mta_dir: " << std::endl;
  std::cin >> mta_dir;

  // Run domino func
  spam_detection(smtp_mta, mail_counter, mta_dir);

  std::cout << "The updated values of p.smtp_mta, mail_counter and mta_dir are " << smtp_mta << ", " << mail_counter << ", " << mta_dir << std::endl;
  return 0;
}
