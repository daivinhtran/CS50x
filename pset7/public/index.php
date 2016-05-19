<?php

    // configuration
    require("../includes/config.php"); 


    //define contents to display in portfolio page
    $positions = [];
    $rows = query("SELECT symbol, shares FROM stocks where id = ?", $_SESSION["id"]);
    $cash = query("SELECT cash, id FROM users where id = ?", $_SESSION["id"]);
	foreach ($rows as $row)
	{
	    $stock = lookup($row["symbol"]);
	    if ($stock !== false)
	    {
	        $positions[] = [
	            "name" => $stock["name"],
	            "price" => $stock["price"],
	            "shares" => $row["shares"],
	            "symbol" => $row["symbol"],
	            "value" => $row["shares"]*$stock["price"]
	        ];
	    }
	}
	//echo($cash[0]["cash"]);
	// render portfolio
	render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "cash" => $cash[0]["cash"]]);
?>
