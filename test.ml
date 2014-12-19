open Sys;;
open String;;
open List;;
open Array;;
open Str;;
open Printf;;

class c_var (name_init : string) =
	object
		val name = name_init
		method get_name = name
	end
;;

class c_struct (name_init : string) (linedef_init : int) (fileindex_init : int) =
	object
		val name = name_init
		val linedef = linedef_init
		val fileindex = fileindex_init
		val varList = []
		method get_name = name
		method get_linedef = linedef
		method get_fileindex = fileindex
		method print =
			print_endline("name: " ^ name);
			print_endline("linedef: " ^ string_of_int(linedef));
			print_endline("fileindex: " ^ string_of_int(fileindex));
	end
;;

let prints x = print_endline("<" ^ x ^ ">");;

let ft_out file message =
	let oc = open_out file in    (* create or truncate file, return channel *)
		fprintf oc "%s\n" message;   (* write something *)
		close_out oc
;;

let ft_in filename =
	let lines = ref [] in
		let chan = open_in filename in
		try
			while true; do
				lines := input_line chan :: !lines
			done; []
		with e ->
			close_in chan;
			List.rev !lines
;;

let ft_concat path file = path ^ file;;

let init folder =
		let check file = if file = folder then
			let concat file = ft_concat(folder)(file) in
				Array.iter(Sys.remove)(Array.map(concat)(Sys.readdir(file))) in
	Array.iter(check)(Sys.readdir("."))
;;

let readArray = ref [||];;

let ft_read folder =
		let inclist = Sys.readdir(folder) in
			let clist = Array.map(ft_concat(folder))(inclist) in
				let read = Array.map(ft_in)(clist) in
					let trim x = List.map(String.trim)(x) in
						readArray := Array.map(trim)(read);
	!readArray
;;

let structList = ref [];;

let getstructList () =
	let static_int1 = ref 0 in
	let static_int2 = ref 0 in

	let test_struct = Str.regexp(".*struct.*") in
	let test_name = Str.regexp(".*struct.+\\(s_.+\\)") in

	let add_struct s i1 i2 = structList := (new c_struct(s)(i1)(i2) :: !structList) in

	let get_struct s =
		if (string_match(test_struct)(s)(0)) then
			if (string_match(test_name)(s)(0)) then
				add_struct(matched_group(1)(s))(!static_int1)(!static_int2);
		static_int1 := !static_int1 + 1; in

		let g x =
			List.iter(get_struct)(x);
			static_int1 := 0;
			static_int2 := !static_int2 + 1; in
				Array.iter(g)(!readArray);

	structList := List.rev !structList
;;

let buildstructList () =
	let end_struct = Str.regexp("}.*;") in

	let get_var structElem file line =
		let i = line;
		while string_match(end_struct)(List.nth(!readArray.(file))(i)) do

		done in


	let foreach structElem = get_var(structElem)(structElem#get_fileindex)(structElem#get_linedef) in
		List.map(foreach)(!structList)
;;

let printstructList () = List.iter(function ot -> ot#print)(!structList);;

init("./src/");;
ft_read("./inc/");;
getstructList();;
printstructList();;

