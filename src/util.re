let cx = (classNames: list((string, bool))) =>
  classNames
  |> List.fold_left(
       (curClass, (c, p)) => p ? {j|$curClass $c|j} : curClass,
       "",
     );
