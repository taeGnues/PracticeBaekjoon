def solution(id_list, report, k):
    
    report_lists = {
        id : set() for id in id_list
    }
    mail_sending_cnt = {
        id : 0 for id in id_list
    }
    
    for r in report:
        reportId, reportedId = r.split()
        report_lists[reportedId].add(reportId)

    
    for reportIds in report_lists.values():
        if len(reportIds) >= k:
            for r in reportIds:
                mail_sending_cnt[r] += 1
        
    return list(mail_sending_cnt.values())