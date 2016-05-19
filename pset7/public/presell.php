<?php

    // configuration
    require("../includes/config.php"); 


    //define contents to display in portfolio page

    $rows = query("SELECT symbol FROM stocks where id = ?", $_SESSION["id"]);

	foreach ($rows as $row)
	{
	    $stock = lookup($row["symbol"]);
	    if ($stock !== false)
	    {
	        $positions[] = [
	            "symbol" => $row["symbol"],
	        ];
	    }
	}
	//echo($cash[0]["cash"]);
	// render portfolio
	if(empty($positions))
	{
		redirect("/");
	}
	else
		render("sell_form.php", ["positions" => $positions, "title" => "Sell"]);
?>
