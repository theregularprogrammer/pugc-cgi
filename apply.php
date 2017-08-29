<?php include_once("header.php"); ?>

	<!-- APPLICATION FORM -->
		<form id="application" action="/cgi-bin/pugc/application.cgi" method="post">

			<input type="text" name="name" placeholder="Your Name...">
			<input type="text" name="address" placeholder="Your Address...">
			<input type="text" name="city" placeholder="Your City...">
			<input type="text" name="district" placeholder="Your District...">
			<input type="text" name="province" placeholder="Your Province...">
			<input type="number" name="cnic" placeholder="Your CNIC...">
			<input type="number" name="phone" placeholder="Your Phone Number...">
			<input type="radio" name="gender" value="Male" checked>
			<input type="radio" name="gender" value="Female">
			<input type="radio" name="gender" value="Other">
			<input type="numbe " name="intertotalmarks" placeholder="Inter Total Marks...">
			<input type="number" name="intermarks" placeholder="Inter Obtained Marks...">
			<input type="number" name="matrictotalmarks" placeholder="Matric Total Maarks...">
			<input type="number" name="matricmarks" placeholder="Matric Obtained Marks...">
			<input type="radio" name="degree" value="BSIT">
			<input type="radio" name="degree" value="BBA">
			<input type="radio" name="degree" value="LL.B">
			<input type="radio" name="degree" value="English Literature">
			<input type="radio" name="degree" value="History">

			<input type="submit" id="submit" name="submit" value="FINISH">



		</form>
	<!-- /APPLICATION FORM -->

<?php include_once("footer.php"); ?>
