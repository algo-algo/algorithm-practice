package leetcode;

import java.util.ArrayList;
import java.util.List;

public class leetcode165 {

    private List<Integer> getRevisionList(String version){
        List<Integer> vList = new ArrayList<>();
        for(String revision: version.split("\\.")){
            vList.add(Integer.parseInt(revision));
        }
        return vList;
    }

    public int compareVersion(String version1, String version2) {
        List<Integer> v1List = getRevisionList(version1);
        List<Integer> v2List = getRevisionList(version2);

        int smallSize = (v1List.size() < v2List.size() ?  v1List.size() : v2List.size());
        for(int i = 0 ; i < smallSize;i++){
            if(v1List.get(i) == v2List.get(i))
                continue;
            else if(v1List.get(i) < v2List.get(i))
                return -1;
            else
                return 1;
        }

        if(v1List.size() == v2List.size())
            return 0;
        else if(v1List.size() < v2List.size()){
            for(int i = v1List.size() ; i< v2List.size();i++){
                if(v2List.get(i) > 0)
                    return -1;
            }
            return 0;
        }
        else{
            for(int i = v2List.size() ; i< v1List.size();i++){
                if(v1List.get(i) > 0)
                    return 1;
            }
            return 0;
        }
    }
}
