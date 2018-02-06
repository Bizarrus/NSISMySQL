OutFile "Example.exe"
Unicode true
# must have a space below to remove the "Nullsoft system vXX.XX" at the bottom
BrandingText " "

# default section
Section
   MySQL::SetCredentials "localhost" 3306 "banananode" "root" ""
   MySQL::Query "SELECT * FROM WHATEVER"
SectionEnd
