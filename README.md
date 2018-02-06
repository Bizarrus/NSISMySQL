# NSIS: MySQL

# Installation
Move `MySQL.dll` to your `NSIS` directory, for sample:

`ANSI\MySQL.dll` > `C:\Program Files (x86)\NSIS\Plugins\x86-ansi\MySQL.dll`

`Unicode\MySQL.dll` > `C:\Program Files (x86)\NSIS\Plugins\x86-unicode\MySQL.dll`

# Usage
## Set connection Informations

	MySQL::SetCredentials <Hostname> <Port> <Database> <Username> <Password>
**Example**
	
	MySQL::SetCredentials "localhost" 3306 "mysql" "root" ""
	
## Query
	
	MySQL::Query <Statement>
	
**Example**

		MySQL::Query "CREATE DATABASE IF NOT EXISTS `demo`;"
