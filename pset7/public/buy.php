<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy Stock"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["stockbuy"]) OR empty($_POST["sharesbuy"]))
        {
            apologize("You must provide a stock name and number of shares you want to buy");
        }
        if (preg_match("/^\d+$/", $_POST["sharesbuy"]) == false)
        {
            apologize("Invalid number of shares");
        }

        $stock = lookup($_POST["stockbuy"]);

        if (count($stock) == 3)
        {
            // query database for user        
            $cashs = query("SELECT cash FROM users WHERE id =?", $_SESSION["id"]);
            $cash = $cashs[0]["cash"];
            
            if($cash - $stock["price"]*$_POST["sharesbuy"] < 0)
            {
                apologize("You don't have enough cash");
            }
            else
            {
                query("UPDATE users SET cash = cash - ? WHERE id = ?", $stock["price"]*$_POST["sharesbuy"], $_SESSION["id"]);
            }
            query("INSERT INTO stocks (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], strtoupper($_POST["stockbuy"]), $_POST["sharesbuy"]);
            query("INSERT INTO history (id, action, time, symbol, shares, price) VALUES (?, 'Buy', ?, ?, ?, ?)", $_SESSION["id"], $CURRENT_TIMESTAMP, strtoupper($_POST["stockbuy"]), $_POST["sharesbuy"], $stock["price"]);
             
            redirect("/");
        }
        // else apologize
        else
            apologize("Invalid stock input");
    }

?>
