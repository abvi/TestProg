<?php

function hasUniqueChars($str)
{
	$seenChars = array();
	for ($i = 0; $i < strlen($str); $i++)
	{
		$ch = $str[$i];
		if (array_key_exists($ch, $seenChars) && $seenChars[$ch])
		{
			return "0";
		}

		$seenChars[$ch] = $ch;
	}

	return "1";
}

$strArr = array("aabbcc", "abcdef");
foreach ($strArr as $str)
{
	echo "$str = " . hasUniqueChars($str) . "\n";
}
