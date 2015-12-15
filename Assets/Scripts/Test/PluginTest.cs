using UnityEngine;
using System.Collections;
using System.Runtime.InteropServices;

public class PluginTest : MonoBehaviour
{
    [DllImport("SSEngine")]
    private static extern int CreateSimpleObj(int value);

    [DllImport("SSEngine")]
    private static extern int SetSimpleObjValue(int id, int val);

    [DllImport("SSEngine")]
    private static extern int GetSimpleObjValue(int id);

    [DllImport("SSEngine")]
    private static extern int DeleteSimpleObj(int id);
    [DllImport("SSEngine")]
    private static extern void CleanUp();

    int objId = -100;
    int objId1 = -100;
	void Start () {
        objId = CreateSimpleObj(100);
        Debug.Log(objId);
        Debug.Log(GetSimpleObjValue(objId));
        Debug.Log(SetSimpleObjValue(objId, 50));
        Debug.Log(GetSimpleObjValue(objId));
        objId1 = CreateSimpleObj(150);
        Debug.Log(objId1);
        Debug.Log(GetSimpleObjValue(objId1));
        Debug.Log(SetSimpleObjValue(objId1, 150));
        Debug.Log(GetSimpleObjValue(objId));
        Debug.Log(GetSimpleObjValue(objId1));
        Debug.Log(DeleteSimpleObj(objId));
        Debug.Log(DeleteSimpleObj(objId1));
        CleanUp();
	}
	

	void Update () {
	}
}
