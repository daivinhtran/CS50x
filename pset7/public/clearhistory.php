<?php

    // configuration
    require("../includes/config.php"); 


    //define contents to display in portfolio page
 	query("DELETE FROM history WHERE id = ?", $_SESSION["id"]);

	// render history form
	redirect("/");
?>
