import Test 1.0
import Qt 4.7

QtObject {
    property variant other
    other: MyTypeObject { id: obj }
    property alias enumAlias: obj.enumProperty;
}

