package test.record.with.sealed;

public class TestRecordWithSealed {

}

@SuppressWarnings("preview")
sealed interface MathematicalOperation
		permits AddOperation,SubtractOperation,MyOperation,OtherOperation {
}

@SuppressWarnings("preview")
record AddOperation(int i, int j) implements MathematicalOperation {

}

@SuppressWarnings("preview")
record SubtractOperation(int i, int j) implements MathematicalOperation {

}

@SuppressWarnings("preview")
record MyOperation(MathematicalOperation mo) implements MathematicalOperation {

}

@SuppressWarnings("preview")
record OtherOperation(AddOperation ao, SubtractOperation so) implements MathematicalOperation {

}
