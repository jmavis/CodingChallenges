/// Author Jared Mavis
/// Username jmavis
/// Code Eval JSON Menu Ids
/// Prints the sum of all items that have a label and id
var fs  = require("fs");
fs.readFileSync(process.argv[2]).toString().split('\n').forEach(function (line) {
    if (line !== "") {
        //do something here
        try {
        	var lineJson = JSON.parse(line);
	        var idSum = 0;
	        lineJson.menu.items.map(function(item){
	        	if (item && item.id && item.label){
	        		idSum += item.id;
	        	}
	        });
	        console.log(idSum);
        } catch (e){
        }
    }
});