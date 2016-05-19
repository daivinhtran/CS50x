<?php

    // configuration
    require("../includes/config.php"); 


    //define contents to display in portfolio page
    $rows = query("SELECT action, time, symbol, shares, price FROM history where id = ?", $_SESSION["id"]);
    $positions = [];
	foreach ($rows as $row)
	{
	    $positions[] = [
	        "action" => $row["action"],
	        "time" => $row["time"],
	        "symbol" => $row["symbol"],
	        "shares" => $row["shares"],
	        "price" => $row["price"]
	    ];

	}

	// render history form
	render("history_form.php", ["positions" => $positions, "title" => "History"]);
?>
