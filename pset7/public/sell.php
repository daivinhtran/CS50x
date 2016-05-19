<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("presell.php", ["title" => "Sell"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["stocksell"]))
        {
            apologize("You must select a stock name");
        }

        $shares = query("SELECT shares FROM stocks WHERE id =? AND symbol = ?", $_SESSION["id"], $_POST["stocksell"]);
        
        if($shares != false)
        {
            $share = $shares[0]["shares"];
        }
        else
        {
            apologize("SOMETHING WENT WRONG!");
        }


        if(query("DELETE FROM stocks WHERE id = ? AND symbol = ?",$_SESSION["id"], $_POST["stocksell"]) === false)
        {
            apologize("SOMETHING WENT SO WRONG!!!");
        }
        else
        {
            $stock = lookup($_POST["stocksell"]);

            query("UPDATE users SET cash = cash + ?*? WHERE id = ?", $share, $stock["price"],
                 $_SESSION["id"]);
             query("INSERT INTO history (id, action, time, symbol, shares, price) VALUES (?, 'Sell', ?, ?, ?, ?)", $_SESSION["id"], $CURRENT_TIMESTAMP, strtoupper($_POST["stocksell"]), $share, $stock["price"]);
            redirect("/");
        }
    }
?>

