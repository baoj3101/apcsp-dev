<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>RSA Demo</title>
</head>

<style type="text/css">
html { 
  background: url(josehua_tree.jpg) no-repeat center center fixed; 
  -webkit-background-size: cover;
  -moz-background-size: cover;
  -o-background-size: cover;
  background-size: cover;
}
* {
    box-sizing: border-box;
}
/* Style the body */
body {
    font-family: Arial;
    margin: 0;
}
/* Header/logo Title */
.header {
    padding: 10px;
    text-align: center;
    /*background: #1abc9c;*/
         background: none;
    color: white;
}
/* Increase the font size of the heading */
.header h1 {
    font-size: 50px;
         font-family: Tahoma, Geneva, sans-serif;
         font-weight: lighter;
}
.header h3 {
    font-size: 28px;
         font-family: Tahoma, Geneva, sans-serif;
         font-weight: lighter;
}
</style>

<body id=”background”>

<?php 
   // define variables and set to empty values
   $arg1 = $arg2 = $output = $retc = "";

   if ($_SERVER["REQUEST_METHOD"] == "POST") {
      $arg1 = test_input($_POST["arg1"]);
      $arg2 = test_input($_POST["arg2"]);
      exec("/usr/lib/cgi-bin/student4/rsa " . $arg1 . " '" . $arg2 . "'", $output, $retc); 
   }

   function test_input($data) {
      $data = trim($data);
      $data = stripslashes($data);
      $data = htmlspecialchars($data);
      return $data;
   }
?>

<div style="background-color:white;color:black;align:center;width:800px;height:180px;margin:auto;">
<h3 align="center">RSA Encryption/Descryption Demo</h3>
<form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
<table style="color:black">
<tr>
  <td><p>Random Seed</p></td><td><input type="text" name="arg1" value="100" size=30></td>
</tr>
<tr>
  <td><p>Message</p></td><td><input type="text" name="arg2" value="Hello World!" size=30></td>
  <td><input type="submit" value="RUN"></td>
</tr>
</table>
</form>

</div>

<br>

<div style="background-color:white;align:center;width:800px;height:600px;margin:auto;overflow:scroll">
<?php
   echo "<h2>C Program Input:</h2>";
   echo $arg1;
   echo "<br>";
   echo $arg2;
   echo "<br>";

   echo "<h2>C Program Output:</h2>";
   echo "<pre>";
   foreach ($output as $line) {
      echo $line;
      echo "<br>";
   }
   echo "</pre>";
?>
</div>

</body>
</html>
